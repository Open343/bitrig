# The client writes a message to Sys::Syslog native method.
# The syslogd writes it into a file and through a pipe.
# The syslogd passes it via TLS to localhost loghost.
# The cafile does not exist.
# Find the message in client, file, pipe, syslogd log.
# Check that syslogd has verify failure and server has no message.

use strict;
use warnings;
use Socket;

our %args = (
    syslogd => {
	loghost => '@tls://localhost:$connectport',
	loggrep => {
	    qr/open CAfile: No such file or directory/ => 2,
	    qr/Logging to FORWTLS \@tls:\/\/localhost:\d+/ => '>=4',
	    qr/syslogd: tls_connect_socket .*: /.
		qr/ssl verify memory setup failure/ => 2,
	    get_testgrep() => 1,
	},
	cacrt => "noexist",
    },
    server => {
	listen => { domain => AF_UNSPEC, proto => "tls", addr => "localhost" },
	up => "IO::Socket::SSL socket accept failed",
	down => "Server",
	exit => 255,
	loggrep => {
	    qr/listen sock: (127.0.0.1|::1) \d+/ => 1,
	    qr/SSL accept attempt failed because of handshake problems/ => 1,
	    get_testgrep() => 0,
	},
    },
);

1;
