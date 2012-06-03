<?php
/**
 * User: koglinjg
 * Date: 6/2/12
 */
//@Version 0.3

//DEBUG
//ini_set('display_errors', 1);
//error_reporting(E_ALL);

if (@file_exists('config.php')) {
  include_once('config.php');
} else {
  die('Please make a config.php file.');
}
if (in_array($_SERVER['REMOTE_ADDR'], $config['remoteip'], TRUE) && $_SERVER['REQUEST_METHOD'] === "GET") {
  $result = array('error' => 0, 'error_message' => '', 'apc_mon_version' => '0.3');
  $keys = explode(',', $_GET['check']);
  foreach ($keys as $key) {
    try {
      if (@file_exists($config['include_dir'])) { //suppress warning about the file not existing
        $file = $config['include_dir'] . '/' . $key . '.inc';
        if (@file_exists($file)) {
          include_once($file);
          if (function_exists($key)) {
            $result['data'][] = call_user_func($key);
          } else {
            $result['debug_message'] = 'Include file "' . $key . '.inc" exists but did not define function ' . $key . '.';
            throw new Exception(serialize($result));
          }
        } else {
          $result['debug_message'] = 'Include file "' . $key . '.inc" doesn\'t exists.';
          include_once($config['include_dir'] . '/list_valid_checks.inc');
          $checks = list_all_checks($config);
          $result['error'] = 1;
          $result['error_message'] = "INVALID_KEY: Valid values are: ($checks)";
        }
      } else {
        $result['debug_message'] = 'Include directory "' . $config['include_dir'] . ' doesn\'t exists.';
        throw new Exception(serialize($result));
      }
    } catch (Exception $e) {
      die($e->getMessage());
    }
  }
  print(serialize($result));
}