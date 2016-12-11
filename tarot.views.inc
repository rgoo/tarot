<?php

/**
 * Implements hook_views_data().
 */
function tarot_views_data() {
  $data = array();

  // data[tableName][table][group] = human readable name of table.
  $data['tarot_cards']['table']['group'] = t('Tarot Cards');

  // tells drupal that tarot_cards is a table in the db
  // and that views can use it
  $data['tarot_cards']['table']['base'] = array(
    'title' => t('Tarot Cards'),
    'help' => t('Stores tarot card data.'),
  );

  // HOW TO: expose our table columns to views
  // [tableName][column]
  $data['tarot_cards']['card_id'] = array(
    'title' => t('Card ID'),
    'help' => t('The card number.'),

    // This tells Views that the column can be used for display purposes,
    // specifies what Field Handler should be responsible for building its
    // SQL, rendering its value to the user, and so on.
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    // This tells Views that the column can be used for sorting, and
    // specifies what Sort handler should be responsible for building its
    // ORDER BY clause, settings page, etc. We're using the built-in handler.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // This tells Views that the column can be used for filtering, and
    // specifies what Filter handler should be responsible for building its
    // WHERE clause, settings page, etc. We're using the built-in handler.
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['tarot_cards']['name'] = array(

    'title' => t('Card Name'),
    'help' => t('The card name.'),
    'field' => array(
      'handler' => 'views_handler_field_custom',
     ),
  );

  return $data;
}
