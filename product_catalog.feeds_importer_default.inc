<?php
/**
 * @file
 * product_catalog.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function product_catalog_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'catalog_feed';
  $feeds_importer->config = array(
    'name' => 'Catalog Feed',
    'description' => 'Import products from copiercatalog.com',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Nid',
          'xpathparser:1' => 'Product',
          'xpathparser:2' => 'Manufacturer',
          'xpathparser:3' => 'Color-or-Black--amp--White',
          'xpathparser:4' => 'Family',
          'xpathparser:5' => 'Type',
          'xpathparser:7' => 'Virtual-Demo',
          'xpathparser:8' => 'Price',
          'xpathparser:9' => 'Summary',
          'xpathparser:10' => 'Highlights',
          'xpathparser:11' => 'Body',
          'xpathparser:12' => 'Primary-Image',
          'xpathparser:20' => 'Primary-Image-Alt',
          'xpathparser:13' => 'Secondary-Image-1',
          'xpathparser:14' => 'Secondary-Image-1-Alt',
          'xpathparser:15' => 'Secondary-Image-2',
          'xpathparser:16' => 'Secondary-Image-2-Alt',
          'xpathparser:17' => 'Secondary-Image-3',
          'xpathparser:18' => 'Secondary-Image-3-Alt',
          'xpathparser:19' => 'Speed',
          'xpathparser:21' => 'Brochure',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:20' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:21' => 0,
        ),
        'context' => '//node',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:20' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:21' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_catalog_manufacturer',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_color_or_black_white',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_catalog_family',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_catalog_virtual_demo:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_price',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_summary',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_highlights',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'xpathparser:11',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_primary_image:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_primary_image:alt',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_secondary_image_1:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_secondary_image_1:alt',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_secondary_image_2:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_secondary_image_2:alt',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_secondary_image_3:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_secondary_image_3:alt',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_speed2',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_catalog_brochure',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'catalog_product',
        'language' => 'und',
      ),
    ),
    'content_type' => 'catalog_feed',
    'update' => 0,
    'import_period' => '604800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['catalog_feed'] = $feeds_importer;

  return $export;
}
