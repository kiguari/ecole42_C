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
 * @package WordPress */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'wordpress');

/** MySQL database username */
define('DB_USER', 'Eshakita');

/** MySQL database password */
define('DB_PASSWORD', 'Eshakita');

/** MySQL hostname */
define('DB_HOST', 'mysql-service:3306');

/** Database Charset to use in creating database tables. */
define('DB_CHARSET', 'utf8');

/** The Database Collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '!_=2:%4$TIN6s;+v RF Ek_nZ{+F](47}DJ4`Zl}31rG=|RM6fL[|o<kcJWc2EcR');
define('SECURE_AUTH_KEY',  'a5./7&^3ZPv.OEZe$G^[.RiUf !G9^k7iG72kDyZ4n%Pri4E{WDgg~&y /FvOCdx');
define('LOGGED_IN_KEY',    '8r4<b4[W~yn$;w/cpc|;|Bia&&IZvNpjij/.)?S.?eSWA=}F/8c|8e_`uo%Bwp_2');
define('NONCE_KEY',        '.K|+j.&Ez#G^7]H:PO,8tN_QU^l[c$;P^Kt)*LqAdFu6Q!T]|+J>=;*58]x-VMC~');
define('AUTH_SALT',        '{n|JzS0wS_lqd7fo ++2qfxePxT]=@M3||zY11V<{q&0^+$->w(],8k_ HZ(*yJa');
define('SECURE_AUTH_SALT', 'R|v|~2<|&J&51Ze36P*|VKxugLrwHb+uU_by|zgZkx:P%YHY|^*5aO~k]HH?D*D(');
define('LOGGED_IN_SALT',   'J<=IDx+wF343tgzJRM{~6GV$Ol2-[V_i^4a39%0J{>8=bg%H|_|*2GiW]+$+/C!%');
define('NONCE_SALT',       'ufpAM591@mNi=[6rUd5rKB%2^/2Qx4gbv p}T`GhyMKUvazsN2I|~,}w-?-XiMls');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix  = 'wp_';

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
define('WP_DEBUG', false);

/* That's all, stop editing! Happy blogging. */

/** Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');
