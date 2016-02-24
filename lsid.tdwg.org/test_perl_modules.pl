#!/usr/bin/perl

use DBD::mysql;
use SOAP::Lite;
use LWP;
use URI;
use Net::FTP;
use Net::DNS;
use XML::XPath;
use MIME::Base64;
#use MIME::Parser;
use MIME::Tools;
use File::Temp;
use RDF::Core;
use CGI::Application;
use LS;


print "DBD::mysql version: ".$DBD::mysql::VERSION."\n";
print "SOAP::Lite version: ".$SOAP::Lite::VERSION."\n";
print "LWP version: ".$LWP::VERSION."\n";
print "URI version: ".$URI::VERSION."\n";
print "Net::FTP version: ".$Net::FTP::VERSION."\n";
print "Net::DNS version: ".$Net::DNS::VERSION."\n";
print "XML::XPath version: ".$XML::XPath::VERSION."\n";
print "MIME::Base64 version: ".$MIME::Base64::VERSION."\n";
print "MIME::Parser version: ".$MIME::Parser::VERSION."\n";
print "MIME::Tools version: ".$MIME::Tools::VERSION."\n";
print "File::Temp version: ".$File::Temp::VERSION."\n";
print "RDF::Core version: ".$RDF::Core::VERSION."\n";
print "CGI::Application: ".$CGI::Application::VERSION."\n";
print "LS version: ".$LS::VERSION."\n";

