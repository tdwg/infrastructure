#!/usr/bin/perl -w

use WebResolverTest;

use CGI::Carp qw( fatalsToBrowser );

my $webapp = WebResolverTest->new();
$webapp->run();
