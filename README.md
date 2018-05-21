# product_catalog
Drupal 7 feature for importing and displaying products from the copiercatalog.com site, via XML.

## Install & Configure

1. Log into the site and go to _Structure > Features_, and enable the "Product Catalog" feature.
2. Go to Edit shortcuts menu.
   * Click “add link.”
   * Create a link called “Administer Products” with a path of “admin/product-catalog.”
3. Edit Product Catalog Admin view.
   * Click “Bulk operations” under Fields section and select “Publish content” and “Unpublish content.” DO NOT SELECT THE DELETE BULK OPERATION!
   * Click Save.
4. Create Copier Catalog user (Non-Xfactor clients only, skip to step 5 for Xfactor clients)
   * In a new tab, go to www.copiercatalog.com and log in.​
   * Go to People > Add user
   * Click “Add user.”
   * Set user name to be domainname (example.com).
   * Set password to be aSdf1@34.
   * Set email to be domain@brand.com(example@dealermarketingsystems.com).
   * Role should be Authenticated User.
   * Select the appropriate language setting (i.e. International Language for Australian clients..)
   * Click Save.
   * Now edit the newly created user.
   * Scroll to the bottom of the page and select the appropriate manufacturers.
   * Make note of the user ID found in the URL of the edit page.
   * Click Save.
5. Return to client site and create new catalog feed.
   * Go to Configuration > Services > Copier Catalog Settings
   * Enter the User ID of the user account you just created on copiercatalog.com.
