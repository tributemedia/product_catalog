<?php
/**
 * @file
 * product_catalog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function product_catalog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function product_catalog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function product_catalog_image_default_styles() {
  $styles = array();

  // Exported image style: catalog-product-colorbox.
  $styles['catalog-product-colorbox'] = array(
    'label' => 'Catalog Product Colorbox',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: catalog-product-primary.
  $styles['catalog-product-primary'] = array(
    'label' => 'Catalog Product Primary',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 470,
          'height' => 470,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: catalog-product-secondary.
  $styles['catalog-product-secondary'] = array(
    'label' => 'Catalog Product Secondary',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function product_catalog_node_info() {
  $items = array(
    'catalog_feed' => array(
      'name' => t('Catalog Feed'),
      'base' => 'node_content',
      'description' => t('Import catalog products from copiercatalog.com.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'catalog_product' => array(
      'name' => t('Catalog Product'),
      'base' => 'node_content',
      'description' => t('Products imported from copiercatalog.com'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
