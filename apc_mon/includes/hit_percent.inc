<?php
/**
 * User: koglinjg
 * Date: 6/2/12
 * Time: 4:08 PM
 */

/**
 * @return float
 */
function hit_percent() {
  $info = apc_cache_info();
  $total_hits = $info['num_hits'] + $info['num_misses'];
  return floor((($info['num_hits']) / ($total_hits)) * 100);
}