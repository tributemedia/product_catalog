Requirements
------------

This module requires the following contributed modules:

* Feeds - https://www.drupal.org/project/feeds
* Feeds Tamper - https://www.drupal.org/project/feeds_tamper
* Feed Extensible Parsers - https://www.drupal.org/project/feeds_ex

Installation
------------

Once you have enabled the module complete the following steps before importing any new products.

1. Add the following terms to the "Product Category" taxonomy:
  a. Office Equipment
  b. Software
2. Manage fields for the new Catalog Product content type and set the following default values:
  a. Prodcut Category = Office Equipment
  b. Request Quote Form = Request Quote
3. Navigate to https://www.copiercatalog.com/user and log in.
4. Get the User ID for the client's account on the copier catalog site:
  a. If the client is an existing client (previously using our catalog feature) find the user account for that client and retrieve the User ID.
  b. If the client does not already have an account, create a new account for them.
  c. Once the new account is saved edit the account and select the Manufacturers for their catalog and save.
5. Return to the new site where you are installing the feature.
6. Navigate to Content > Feeds and add a new product catalog feed.
  a. Enter an appropriate title
  b. Enter the following URL in the Feed URL field, replacing [uid] with the User ID of the new account you just added to the copier catalog site.
    - https://www.copiercatalog.com/catalog-product/xml/[uid]
  c. Save and import
