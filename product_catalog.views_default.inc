<?php
/**
 * @file
 * product_catalog.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function product_catalog_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'product_catalog_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product Catalog Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Product Catalog Admin';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_catalog_manufacturer' => 'field_catalog_manufacturer',
    'publishcontent' => 'publishcontent',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_catalog_manufacturer' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'publishcontent' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>This catalog will periodically be updated as new products are available from the manufacturer. You have the option to allow the default products to remain published or unpublished or you can make those changes here. If you would like to add your own products, you can do that as well.</p><p>Using the table below, you can publish or unpublish catalog products directly. Using the check boxes at the left and the \'operations\' pull down, you can delete your items as well. <strong>Note: If you delete an item from the list (rather than unpublish) that item will be removed from your website. It will not be automatically pushed to your website from the copier catalog service. You\'ll need to add it again.</strong></p>
<p>If you\'d like to go to the page of a particular product to view it or edit it, you can click on the model number (title) and it will take you to that page.</p>
<p>If you\'d like to add a product to your catalog, you can add it <a href="/node/add/catalog-product">here</a>.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You do not have any items that match your search criteria. Please try again by editing the title and/or manufacturer fields above.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Manufacturer */
  $handler->display->display_options['fields']['field_catalog_manufacturer']['id'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['field'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'catalog_product' => 'catalog_product',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title (contains)';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Manufacturer (field_catalog_manufacturer) */
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['id'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['field'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['operator_id'] = 'field_catalog_manufacturer_tid_op';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['label'] = 'Manufacturer';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['operator'] = 'field_catalog_manufacturer_tid_op';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['identifier'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['vocabulary'] = 'copier_catalog_manufacturer';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/product-catalog';
  $export['product_catalog_admin'] = $view;

  $view = new view();
  $view->name = 'product_landing_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product Landing Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Product Catalog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'heading';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'It looks like your search returned no results. You can either go back to the advanced search options and try a different search or <a href="/product-catalog">click here to reset your search</a>.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Manufacturer (field_catalog_manufacturer) */
  $handler->display->display_options['relationships']['field_catalog_manufacturer_tid']['id'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['relationships']['field_catalog_manufacturer_tid']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['relationships']['field_catalog_manufacturer_tid']['field'] = 'field_catalog_manufacturer_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Manufacturer */
  $handler->display->display_options['fields']['field_catalog_manufacturer']['id'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['field'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['label'] = '';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_catalog_manufacturer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_catalog_manufacturer']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_catalog_manufacturer']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['delta_offset'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['publishcontent']['id'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['table'] = 'node';
  $handler->display->display_options['fields']['publishcontent']['field'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['label'] = '';
  $handler->display->display_options['fields']['publishcontent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['publishcontent']['element_label_colon'] = FALSE;
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_primary_image']['id'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['table'] = 'field_data_field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['field'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['label'] = '';
  $handler->display->display_options['fields']['field_primary_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_primary_image']['alter']['text'] = '<div class="catalog-product">
<div class="inner">
<div class="catalog-product-image"><div class="inner-inner">[field_primary_image]</div></div>
<div class="catalog-product-manufacturer">[field_catalog_manufacturer]</div>
<div class="catalog-product-title">[title]</div> 
[publishcontent] 
</div>
</div>';
  $handler->display->display_options['fields']['field_primary_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_primary_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_primary_image']['settings'] = array(
    'image_style' => 'catalog-product-secondary',
    'image_link' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Learn More';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col s12 m4 l3 product-catalog product-catalog-grid">
	<div class="equal-height inner">
		<div class="image-wrapper">
         <a href="[path]">
			   <div class="image">[field_primary_image]</div>
         </a>
		</div>
      <div class="manufacturer">[field_catalog_manufacturer]</div>
      <div class="title">[title]</div>
		<div class="learn-more-link">
			<div class="content">[view_node] </div>
		</div>
		<div class="quick-view">
		   <div class="quick-view-button"><a class="colorbox-node" href="[path]">Quick View</a></div>
   	</div>
	</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_catalog_manufacturer_tid';
  /* Sort criterion: Content: Speed (field_speed2) */
  $handler->display->display_options['sorts']['field_speed2_value']['id'] = 'field_speed2_value';
  $handler->display->display_options['sorts']['field_speed2_value']['table'] = 'field_data_field_speed2';
  $handler->display->display_options['sorts']['field_speed2_value']['field'] = 'field_speed2_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'catalog_product' => 'catalog_product',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Model (contains)';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Color or Black &amp; White (field_color_or_black_white) */
  $handler->display->display_options['filters']['field_color_or_black_white_value']['id'] = 'field_color_or_black_white_value';
  $handler->display->display_options['filters']['field_color_or_black_white_value']['table'] = 'field_data_field_color_or_black_white';
  $handler->display->display_options['filters']['field_color_or_black_white_value']['field'] = 'field_color_or_black_white_value';
  $handler->display->display_options['filters']['field_color_or_black_white_value']['group'] = 1;
  $handler->display->display_options['filters']['field_color_or_black_white_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_color_or_black_white_value']['expose']['operator_id'] = 'field_color_or_black_white_value_op';
  $handler->display->display_options['filters']['field_color_or_black_white_value']['expose']['label'] = 'Color or Black & White';
  $handler->display->display_options['filters']['field_color_or_black_white_value']['expose']['operator'] = 'field_color_or_black_white_value_op';
  $handler->display->display_options['filters']['field_color_or_black_white_value']['expose']['identifier'] = 'field_color_or_black_white_value';
  $handler->display->display_options['filters']['field_color_or_black_white_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_color_or_black_white_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_value']['expose']['operator_id'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_type_value']['expose']['operator'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['identifier'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Family (field_catalog_family) */
  $handler->display->display_options['filters']['field_catalog_family_tid']['id'] = 'field_catalog_family_tid';
  $handler->display->display_options['filters']['field_catalog_family_tid']['table'] = 'field_data_field_catalog_family';
  $handler->display->display_options['filters']['field_catalog_family_tid']['field'] = 'field_catalog_family_tid';
  $handler->display->display_options['filters']['field_catalog_family_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_catalog_family_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_catalog_family_tid']['expose']['operator_id'] = 'field_catalog_family_tid_op';
  $handler->display->display_options['filters']['field_catalog_family_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_catalog_family_tid']['expose']['operator'] = 'field_catalog_family_tid_op';
  $handler->display->display_options['filters']['field_catalog_family_tid']['expose']['identifier'] = 'field_catalog_family_tid';
  $handler->display->display_options['filters']['field_catalog_family_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_catalog_family_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_catalog_family_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_catalog_family_tid']['vocabulary'] = 'family';
  /* Filter criterion: Content: Manufacturer (field_catalog_manufacturer) */
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['id'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['field'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['operator_id'] = 'field_catalog_manufacturer_tid_op';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['label'] = 'Manufacturer';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['operator'] = 'field_catalog_manufacturer_tid_op';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['identifier'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['vocabulary'] = 'copier_catalog_manufacturer';
  /* Filter criterion: Content: Speed (field_speed2) */
  $handler->display->display_options['filters']['field_speed2_value']['id'] = 'field_speed2_value';
  $handler->display->display_options['filters']['field_speed2_value']['table'] = 'field_data_field_speed2';
  $handler->display->display_options['filters']['field_speed2_value']['field'] = 'field_speed2_value';
  $handler->display->display_options['filters']['field_speed2_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_speed2_value']['expose']['operator_id'] = 'field_speed2_value_op';
  $handler->display->display_options['filters']['field_speed2_value']['expose']['label'] = 'Speed (field_speed2)';
  $handler->display->display_options['filters']['field_speed2_value']['expose']['operator'] = 'field_speed2_value_op';
  $handler->display->display_options['filters']['field_speed2_value']['expose']['identifier'] = 'field_speed2_value';
  $handler->display->display_options['filters']['field_speed2_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_speed2_value']['group_info']['label'] = 'Speed';
  $handler->display->display_options['filters']['field_speed2_value']['group_info']['identifier'] = 'field_speed2_value';
  $handler->display->display_options['filters']['field_speed2_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '0-20',
      'operator' => 'or',
      'value' => array(
        10 => '10',
        15 => '15',
        20 => '20',
      ),
    ),
    2 => array(
      'title' => '21-40',
      'operator' => 'or',
      'value' => array(
        25 => '25',
        30 => '30',
        35 => '35',
        40 => '40',
      ),
    ),
    3 => array(
      'title' => '41-60',
      'operator' => 'or',
      'value' => array(
        45 => '45',
        50 => '50',
        55 => '55',
        60 => '60',
      ),
    ),
    4 => array(
      'title' => '61-80',
      'operator' => 'or',
      'value' => array(
        65 => '65',
        70 => '70',
        75 => '75',
        80 => '80',
      ),
    ),
    5 => array(
      'title' => '81-100',
      'operator' => 'or',
      'value' => array(
        85 => '85',
        90 => '90',
        95 => '95',
        100 => '100',
      ),
    ),
    6 => array(
      'title' => '100+',
      'operator' => 'or',
      'value' => array(
        101 => '101',
      ),
    ),
    7 => array(
      'title' => 'N/A',
      'operator' => 'or',
      'value' => array(
        0 => '0',
      ),
    ),
  );

  /* Display: Product Catalog Page */
  $handler = $view->new_display('page', 'Product Catalog Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'product-catalog';
  $export['product_landing_page'] = $view;

  return $export;
}
