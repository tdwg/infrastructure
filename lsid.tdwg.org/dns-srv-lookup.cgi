#!/usr/bin/perl -w

use Net::DNS;
use CGI::Carp qw( fatalsToBrowser );

my $lsid = $ARGV[0];
error('No LSID provided') unless ($lsid);

my @parts = split(/:/, $lsid);
my $count = @parts;
error('Invalid LSID: '.$lsid) unless (($parts[0] eq 'urn') && ($parts[1] eq 'lsid') && ($count >= 5) && ($count <= 6)); 

my $srvRecord = '_lsid._tcp.'.$parts[2];

my $res = Net::DNS::Resolver->new;
my $answer = $res->send($srvRecord, 'SRV');
my @packets = $answer->answer;
my $pktCount = @packets;

error("DNS SRV record '$srvRecord' not found.") unless ($pktCount);

my $srvPacket = $packets[0];
my $type = $srvPacket->type;

error("Wrong type '$type' for DNS SRV record.") unless ($type eq 'SRV');

my $target = $srvPacket->target;
my $port   = $srvPacket->port;

print "Content-type: text/xml\n";
print "HTTP Status Code: HTTP/1.1 200 Ok\n\n";
print "<?xml version=\"1.0\"?>\n<lookup><srv hostname=\"$target\" port=\"$port\" /></lookup>\n";

# ==========================
sub error {
 	my $msg = shift;
 	print "Content-type: text/xml\n";
 	print "HTTP Status Code: HTTP/1.1 500 $msg\n\n";
	print "<?xml version=\"1.0\"?>\n<lookup><error>$msg</error></lookup>\n";
	exit;
}
# ==========================
