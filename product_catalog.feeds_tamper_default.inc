<?php
/**
 * @file
 * product_catalog.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function product_catalog_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_feed-xpathparser_10-explode';
  $feeds_tamper->importer = 'catalog_feed';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '~',
    'limit' => '',
    'real_separator' => '~',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['catalog_feed-xpathparser_10-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_feed-xpathparser_21-find_replace';
  $feeds_tamper->importer = 'catalog_feed';
  $feeds_tamper->source = 'xpathparser:21';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'http://www.copiercatalog.com/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['catalog_feed-xpathparser_21-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_feed-xpathparser_21-find_replace_https';
  $feeds_tamper->importer = 'catalog_feed';
  $feeds_tamper->source = 'xpathparser:21';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'https://www.copiercatalog.com/',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['catalog_feed-xpathparser_21-find_replace_https'] = $feeds_tamper;

  return $export;
}
