<?php
 /**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'db_Eshakita_wp' );

/** MySQL database username */
define( 'DB_USER', 'Eshakita' );

/** MySQL database password */
define( 'DB_PASSWORD', 'Eshakita' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '*t*2k|+p/-42--B$rC+;ol>D75T8mtvkx_60gEZ$%ZJX+eYCCdM+(EMdo(!?U?Ll');
define('SECURE_AUTH_KEY',  'X%z]DAiN&9K;uBnguB!kE7@/t@kw&kBz4Zv Zb5txj7t+[$$^,VtjB8;7l f[A=~');
define('LOGGED_IN_KEY',    'si@k~d=8t!eFa1Y~G|&a?zXGdi|1Cp gsFH-+c[uxw!;zGY~)Wy$G*%/PP1Cb:Z[');
define('NONCE_KEY',        '$9+J(rH6YAgqW+ ?a&2}I$5rT[k| &k3iQ?A;FDm%ZKS|Q4w^;-L|+A-|O<)>,Za');
define('AUTH_SALT',        'X^RS|!b`7t+,z*VX]+5RJ5+-_|$<o&GhHLD4{tgd7EXCOA ~1EWmijh|Pb5.fE$ ');
define('SECURE_AUTH_SALT', '5Do7 CJjK|{4([TSml-=[m1mHqr;6F*-2FcwJQC[u&A-XaLgFXL+a{4C<o*,[;<P');
define('LOGGED_IN_SALT',   '}GU8bF`mfu(^JU$@=+VYrV3FB/*M:(3.$.B<fCVbVF*QcP3)[{Dqm`vk;5T4=l)R');
define('NONCE_SALT',       'L{8E;rQz2jB-DdeJMtcpM1TATj$f?r_$zn!mW#@`]PHDv(i/]kTFR}W]n>K|>X,d');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );

