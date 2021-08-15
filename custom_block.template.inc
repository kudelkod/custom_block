<?php



function template_preprocess_custom_block_theme(&$variables) {

  $current_user  = Drupal::currentUser()->id();

  $database = Drupal::database()->select('commerce_product_field_data', 'pf');
  $database->addField('pf', 'title');
  $database->condition('pf.uid', $current_user);
  $count = $database->countQuery()->execute()->fetchField();

  $store = Drupal::database()->select('commerce_store_field_data', 'nd');
  $store->addField('nd', 'name');
  $store->addField('nd', 'store_id');
  $store->condition('nd.uid', $current_user);

  $store_obj = $store->execute()->fetchAll(PDO::FETCH_ASSOC);
  $variables['user_name'] = \Drupal::currentUser()->getAccountName();
  $variables['user_id'] = $current_user;
  $variables['count'] = $count;
  $variables['store_obj'] = $store_obj;
}
