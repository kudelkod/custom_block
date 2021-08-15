<?php
namespace Drupal\custom_block\Plugin\Block;

/**
 * Provides a custom_block.
 *
 * @Block(
 *   id = "custom_block",
 *   admin_label = @Translation("Custom block"),
 *   category = @Translation("Custom block example")
 * )
 */


use Drupal\commerce_product\Entity\Product;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Cache\UncacheableDependencyTrait;

class CustomBlock extends BlockBase {

  use UncacheableDependencyTrait;

  public function build()
  {


    return [
      "#theme" => "custom_block_theme"
    ];
  }
}
