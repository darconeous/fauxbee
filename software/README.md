Fauxbee v0.1
============

Work in progress.

## Planned Software Features ##

 * IPv6/6LoWPAN
 * Serial Port Server (Inbound TCP -> UART)
 * Serial Port Client (UART -> TCP connection to a specific host/port)
 * CoAP-13 interface for control and configuration
 * AT command interface on UART for control and configuration
 * I/O pin configuration/observation/control
 * ADC pin configuration/observation
 * PWM pin configuration/observation/control
 * Most or all of the capabilities of the Digi XBee boards.

## Planned Supported Target Platforms ##

 * `fauxbee` - Original CC2530-based "Fauxbee" board.
 * `avr-raven`
 * `zigbit`
 * `minimal-net`

------------------------------------------

## Settings

 * Serial Passthru
   - Server/Host
   - Destination/Source Host and Port
   - UART settings (Baud, stop bits, flow control, etc)
 * Network Settings
   - 802.15.4 Channel/PAN
   - Hostname
   - Device Password
 * I/O Pins
   - Name
   - Pin
   - Mode (In/Out/PWM/ADC)
   - Value (High/Low/Percentage)
   - Action (Push to URL)
 * Groups
   - Name
   - Address
   - Path remapping
 * Sensors (If available)
   - Voltage
   - Temperature

------------------------------------------

## Path structure

 * /.well-known/core - Service discovery
 * /.cf/hn - hostname
 * /.cf/pa - 802.15.4 pan-id
 * /.cf/ch - 802.15.4 channel
 * /.cf/tp - Maximum transmit power
 * /.cf/rp - RDC type (power-saving radio-sleeping modes)
 * /.cf/ac - autoconnect/autodial
 * /.cf/sm - serial mode (server/host)
 * /.cf/sh - serial client destination host
 * /.cf/sp - serial client destination port
 * /.cf/sf - serial port flow control
 * /.cf/sb - serial port baud
 * /.cf/dn - dns server
 * /.cf/px - proxy server
 * /.cf/pw - device password
 * /.cf/ax - escape sequence
 * /.cf/vh/[vh-index]/vn - vhost/group name
 * /.cf/vh/[vh-index]/va - address
 * /.cf/vh/[vp-index]/vp - port
 * /.cf/pn/[pin-index]/pn - pin name
 * /.cf/pn/[pin-index]/ln - local name
 * /.cf/pn/[pin-index]/fe - features
 * /.cf/pn/[pin-index]/mo - mode
 * /.cf/pn/[pin-index]/de - default state
 * /.cf/pn/[pin-index]/ac - action URL
 * /.cf/pn/[pin-index]/mi - mirror URL
 * /.st/cn - Connected State (on-hook, off-hook, at-mode, etc)
 * /.st/ct - Connection Duration
 * /.st/up - uptime
 * /.ex/at - process an `AT` style modem command.
 * /.ex/sr - Send post contents to serial port. 
 * /[pin-localname]
 * /[pin-index]





