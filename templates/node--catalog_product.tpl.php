<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>

<?php

// Classes for colorbox mode.

$pcPageLeftClass = 'catalog-page-left col-xs-12 col-lg-6 col s12 m6';
$pcPageRightClass = 'catalog-page-right col-xs-12 col-lg-6 col s12 m6';
$colorboxImgClass = 'primary-image primary-colorbox-image';
$imageStyle = 'catalog-product-colorbox';

// Classes for standard mode.

if ($view_mode != 'colorbox') {
	$pcPageLeftClass = 'catalog-page-left col-xs-12 col-sm-4 col-lg-3 col s12 m4';
	$pcPageRightClass = 'catalog-page-right col-xs-12 col-sm-8 col-lg-9 col s12 m8';
	$colorboxImgClass = 'primary-image';
	$imageStyle = 'catalog-product-primary';
}
?>

<style>
.topper-style {
	padding:10px;background:#e2e2e2;clear:both;
}
.dark-region .topper-style {
	padding:10px;background:#666;clear:both;
}
</style>

<?php if ($is_admin && $view_mode != 'colorbox'): ?>
<div class="topper-style">
	<?php if ($status == 0) : ?>
		This page is not-published. If you'd like to publish it, please click the publish link in the tab above.<br />
		You can manage all your products at once <a href="/admin/product-catalog">here</a>.
	<?php elseif ($status == 1) : ?>
		This page is published. If you'd like to unpublish it, please click the unpublish link in the tab above.<br />
		You can manage all your products at once <a href="/admin/product-catalog">here</a>.
	<?php endif; ?>
</div> <!-- topper-style -->
<?php endif; ?>

<?php
$speed = field_get_items('node', $node, 'field_speed2');
$family = field_get_items('node', $node, 'field_catalog_family');

if (!empty($family)){
	$tid = $family[0]['tid'];
	$term = taxonomy_term_load($tid);
	$famName = $term->name;
}else{
	$famName = "";
}

if ($famName == 'Scanner'){
	$action = 'scans';
}else{
	$action = 'prints';
}
?>

<?php if ($view_mode != 'colorbox') : ?>
<div class="catalog-button">Return to <a href="javascript:history.go(-1)">previous search page</a></div>
<?php endif; ?>

<div class="row">
<div class="<?php print $pcPageLeftClass; ?>">
  <div class="inner">
		<div class="<?php print $colorboxImgClass; ?>">
			<?php
			$primary_image = field_get_items('node', $node, 'field_primary_image');

			if (!empty($primary_image)) {
				$image_item = array(
					'style_name' => $imageStyle,
					'path' => $primary_image[0]['uri'],
					'width' => '',
					'height' => '',
					'alt' => $primary_image[0]['alt'],
					'title' => $primary_image[0]['title'],
				);

				$output = theme('image_style', $image_item);
				$file_url = file_create_url($primary_image[0]['uri']);

	      if ($view_mode != 'colorbox') {
	        print l($output, $file_url, array(
						'attributes' => array(
							'class' => 'colorbox'
						),
						'html' => TRUE,
					));
			  } else {
			  	print $output;
			  }
			}
			?>
		</div> <!-- primary-image -->

		<div class="clear-all"></div>

		<?php if ($view_mode != 'colorbox') : ?>
		<div class="secondary_images-wrapper">
			<?php if ($node->field_secondary_image_1) : ?>
			<div class="secondary-images-first secondary-images">
				<?php
				$secondary_image_1 = field_get_items('node', $node, 'field_secondary_image_1');

				if (!empty($secondary_image_1)) {
					$image_item = array(
						'style_name' => 'catalog-product-secondary',
						'path' => $secondary_image_1[0]['uri'],
						'width' => '',
						'height' => '',
						'alt' => $secondary_image_1[0]['alt'],
						'title' => $secondary_image_1[0]['title'],
					);

					$output = theme('image_style', $image_item);
					$file_url = file_create_url($secondary_image_1[0]['uri']);
          print l($output, $file_url, array(
						'attributes' => array(
							'class' => 'colorbox'
						),
						'html' => TRUE,
					));
				}
				?>
			</div>
		  <?php endif; ?>

			<?php if ($node->field_secondary_image_2) : ?>
			<div class="secondary-images-second secondary-images">
				<?php
				$secondary_image_2 = field_get_items('node', $node, 'field_secondary_image_2');

				if (!empty($secondary_image_2)) {
					$image_item = array(
						'style_name' => 'catalog-product-secondary',
						'path' => $secondary_image_2[0]['uri'],
						'width' => '',
						'height' => '',
						'alt' => $secondary_image_2[0]['alt'],
						'title' => $secondary_image_2[0]['title'],
					);

					$output = theme('image_style', $image_item);
					$file_url = file_create_url($secondary_image_2[0]['uri']);
          print l($output, $file_url, array(
						'attributes' => array(
							'class' => 'colorbox'
						),
						'html' => TRUE,
					));
				}
				?>
			</div>
		  <?php endif; ?>

			<?php if ($node->field_secondary_image_3) : ?>
			<div class="secondary-images-third secondary-images">
				<?php
				$secondary_image_3 = field_get_items('node', $node, 'field_secondary_image_3');

				if (!empty($secondary_image_3)) {
					$image_item = array(
						'style_name' => 'catalog-product-secondary',
						'path' => $secondary_image_3[0]['uri'],
						'width' => '',
						'height' => '',
						'alt' => $secondary_image_3[0]['alt'],
						'title' => $secondary_image_3[0]['title'],
					);

					$output = theme('image_style', $image_item);
					$file_url = file_create_url($secondary_image_3[0]['uri']);
          print l($output, $file_url, array(
						'attributes' => array(
							'class' => 'colorbox'
						),
						'html' => TRUE,
					));
				}
				?>
			</div>
		  <?php endif; ?>
		</div>



	  <div class="clear-all"></div>
	 <?php endif; ?>
  </div> <!-- inner -->
	<div class="catalog-links">
		<?php
		$node_wrapper = entity_metadata_wrapper('node', $node);

    if (!empty($node->field_custom_brochure)) {
      $uri = $node->field_custom_brochure[LANGUAGE_NONE][0]['uri'];
      $url = file_create_url($uri);
      $options = array(
        'attributes' => array(
          'target' => '_blank',
          'class' => 'button-red-45',
        ),
      );
      print l('Download Brochure', $url, $options);
    } elseif (!empty($node->field_catalog_brochure)) {
			$manufacturer = reset($node_wrapper->field_catalog_manufacturer->value());
			$manufacturer_name = strtolower(str_replace(' ', '-', $manufacturer->name));
			$brochure = $node_wrapper->field_catalog_brochure->value();
      $brochure_name = explode('/', $brochure);
      $brochure_name = $brochure_name[count($brochure_name) - 1];

			// Check brochure link and re-build if it's a full path
			if(strpos($brochure, 'brochure') !== false) {
			  $brochure = str_replace('https://brochure.copiercatalog.com/' . $manufacturer_name, '', $brochure_name);
      		  $brochure = str_replace('http://brochure.copiercatalog.com/' . $manufacturer_name, '', $brochure_name);

      		  // Some links don't contain the manufacturer name, so these are to cover
      		  // that case.
      		  $brochure = str_replace('https://brochure.copiercatalog.com/', '', $brochure_name);
      		  $brochure = str_replace('http://brochure.copiercatalog.com/', '', $brochure_name);
			}
			elseif(strpos($brochure, 'copier') !== false) {
			  if(strpos($brochure, 'www') !== false) {
			    $brochure = str_replace('https://www.copiercatalog.com/' . $manufacturer_name, '', $brochure_name);
      		    $brochure = str_replace('http://www.copiercatalog.com/' . $manufacturer_name, '', $brochure_name);
      		    $brochure = str_replace('https://www.copiercatalog.com/', '', $brochure_name);
      		    $brochure = str_replace('http://www.copiercatalog.com/', '', $brochure_name);
      		  } 
      		  else {
      		    $brochure = str_replace('https://copiercatalog.com/' . $manufacturer_name, '', $brochure_name);
      		    $brochure = str_replace('http://copiercatalog.com/' . $manufacturer_name, '', $brochure_name);
      		    $brochure = str_replace('https://copiercatalog.com/', '', $brochure_name);
      		    $brochure = str_replace('http://copiercatalog.com/', '', $brochure_name);
      		  }
			}

            print l('Download Brochure', 'http://brochure.copiercatalog.com/'
			. $manufacturer_name . '/' . $brochure, array(
				'attributes' => array(
					'target' => '_blank',
					'class' => 'button-red-45'
				),
			));
		}	?>
		<?php if ($node->field_catalog_virtual_demo) { ?>
			<div class="product-watch-demo">
				<?php print l('Watch Demo Video', $node->field_catalog_virtual_demo[LANGUAGE_NONE][0]['url'], array(
				'attributes' => array(
					'target' => '_blank',
					'class' => 'button-red-45'
				),
				)); ?>
			</div>
		<?php } ?>
		<div class="product-request-quote">
			<?php print l('Request Quote', 'request-quote', array(
			'attributes' => array(
				'class' => 'button-red-45'),
				'query' => array(
					'product' => $title
				),
			)); ?>
		</div>
	</div> <!-- catalog-links -->
</div>
<div class="<?php print $pcPageRightClass; ?>">
	<div class="inner">
		<?php if ($view_mode != 'colorbox') : ?>
		<div class="catalog-info-line-wrapper">
			<div class="inner">
				<div class="catalog-info-line">

					<div class="details col-xs-12 col-sm-6 col s12 m6">
						<?php if ($node->field_color_or_black_white) : ?>
						<div><?php print $node->field_color_or_black_white[LANGUAGE_NONE][0]['value']; ?></div>
				  		<?php endif; ?>

						<?php if ($node->field_catalog_family) : ?>
						<div><?php print render($content['field_catalog_family']); ?></div>
				  		<?php endif; ?>

						<?php if ($view_mode != 'colorbox') :
							if (!empty($speed)) :
								if ($speed[0]['value'] != 0) : //if speed is N/A, don't print anything
								  if ($speed[0]['value'] < 101) : ?>
									  	<div class="product-catalog-speed"><?php print 'Up to '
												. $speed[0]['value'] . ' ' . $action . '/minute'; ?></div>
									<?php else : ?>
										<div class="product-catalog-speed"><?php print 'Over 100 '
											. $action . '/minute'; ?></div>
									<?php endif; endif; endif; endif; ?>
					</div>

				  <div class="manufacturer col-xs-12 col-sm-6 col s12 m6">
						<div class="title">Manufactured by:</div>
						<div class="subtitle"><?php print render($content['field_catalog_manufacturer']); ?></div>
					</div>

				</div>
			</div>
		</div>
	  <?php endif; ?>
		<?php if ($node->field_price) : ?>
		<div class="catalog-srp">
			<div class="catalog-srp-title">Suggested Price</div>
			<div class="catalog-srp-price"><?php print render($content['field_price']); ?></div>
		</div>
	  <?php endif; ?>
		<div class="catalog-summary"><?php print $node->field_summary[LANGUAGE_NONE][0]['value']; ?></div>
		<?php if ($node->field_highlights) : ?>
		<h4>Highlights</h4>
		<?php
		  $highlights = field_get_items('node', $node, 'field_highlights');

		  if (!empty($highlights)) {
		  	print '<ul>';
		  	foreach ($highlights as $highlight) {
		  		print '<li>' . $highlight['value'] . '</li>';
		  	}
		  	print '</ul>';
		  }
	  endif; ?>
		<?php if ($view_mode != 'colorbox') : ?>
		<?php if ($node->body) : ?>
		<div class="catalog-body"><?php print $node->body[LANGUAGE_NONE][0]['value']; ?></div>
	  <?php endif; endif; ?>
	</div>
</div>
</div> <!-- .row -->
