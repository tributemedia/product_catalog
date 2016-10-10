<?php
/**
 * @file
 * product_catalog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function product_catalog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function product_catalog_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function product_catalog_image_default_styles() {
  $styles = array();

  // Exported image style: catalog-product-colorbox.
  $styles['catalog-product-colorbox'] = array(
    'name' => 'catalog-product-colorbox',
    'label' => 'Catalog Product Colorbox',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '480',
          'height' => '480',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: catalog-product-primary.
  $styles['catalog-product-primary'] = array(
    'name' => 'catalog-product-primary',
    'label' => 'Catalog Product Primary',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '470',
          'height' => '470',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: catalog-product-secondary.
  $styles['catalog-product-secondary'] = array(
    'name' => 'catalog-product-secondary',
    'label' => 'Catalog Product Secondary',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '140',
          'height' => '140',
        ),
        'weight' => '1',
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
  return $items;
}
