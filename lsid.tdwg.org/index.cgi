#!/usr/bin/perl -w

use WebResolver;

use CGI::Carp qw( fatalsToBrowser );

my $webapp = WebResolver->new();
$webapp->run();
