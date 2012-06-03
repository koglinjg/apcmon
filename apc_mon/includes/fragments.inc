<?php
/**
 * Copyright: 2012 Joel Koglin
 * apcmon is distributed under the terms of the GPLv3
 * This file is part of apcmon
 */

/**
 * @return int The number extraneous memory fragments
 */
function fragments() {
  $info = apc_sma_info();
  $fragments = 0;
  foreach ($info['block_lists'] as $segments) { //segments is an array of memory segments
    $fragments += count($segments); //count how many chunks there are
  }
  return $fragments - $info['num_seg']; //subtract the number total segments since there has to be one fragment per segment
}