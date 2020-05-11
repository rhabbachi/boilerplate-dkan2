<?php

/**
 * @file
 */

if (!empty(getenv("DOCKSAL_ENVIRONMENT"))) {

  define('ENVIRONMENT', getenv('DOCKSAL_ENVIRONMENT'));
  define('VIRTUAL_HOST', getenv('VIRTUAL_HOST'));

  $databases = array(
    'default' => array(
      'default' => array(
        'username' => getenv("MYSQL_USER"),
        'password' => getenv("MYSQL_PASSWORD"),
        'database' => getenv("MYSQL_DATABASE"),
        'host' => 'db',
        'port' => '',
        'driver' => 'mysql',
        'prefix' => '',
      ),
    ),
  );

  $settings['file_public_base_url'] = "http://" . VIRTUAL_HOST . "/sites/default/files";
}
