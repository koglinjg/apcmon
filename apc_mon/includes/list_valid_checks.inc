<?php
/**
 * User: koglinjg
 * Date: 6/2/12
 * Time: 5:14 PM
 */

/**
 * @param $config
 *
 * @return string A comma separated list of valid checks
 */
function list_all_checks($config) {
  $include_files = array();
  $d = dir($config['include_dir']);
  while (FALSE !== ($entry = $d->read())) {
    if (substr($entry, -4) === '.inc') {
      $check = substr($entry, 0, strlen($entry) - 4); //strip the .inc from the file names
      $include_files[] = $check;
    }
  }

  return implode(', ', array_values($include_files));
}