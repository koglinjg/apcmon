<?php
/**
 * User: koglinjg
 * Date: 6/2/12
 * Time: 4:06 PM
 */

/**
 * @return int The number of times the apc cache has been cleared
 */
function expunges() {
  $info = apc_cache_info();
  return $info['expunges'];
}