<?php
/**
 * @file
 * product_catalog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function product_catalog_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_secondary_images|node|catalog_product|form';
  $field_group->group_name = 'group_secondary_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Secondary Images',
    'weight' => '13',
    'children' => array(
      0 => 'field_secondary_image_1',
      1 => 'field_secondary_image_2',
      2 => 'field_secondary_image_3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-secondary-images field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_secondary_images|node|catalog_product|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Secondary Images');

  return $field_groups;
}
