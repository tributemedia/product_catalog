<?php
/**
 * @file
 * product_catalog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function product_catalog_taxonomy_default_vocabularies() {
  return array(
    'copier_catalog_manufacturer' => array(
      'name' => 'Copier Catalog Manufacturer',
      'machine_name' => 'copier_catalog_manufacturer',
      'description' => 'Name of catalog product manufacturer.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'family' => array(
      'name' => 'Family',
      'machine_name' => 'family',
      'description' => 'Family that a product belongs to (Printer, Scanner, MFP, etc.).',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
