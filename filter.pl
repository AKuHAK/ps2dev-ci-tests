#!/usr/bin/perl

use strict;
use warnings;

# Check for correct number of arguments
if (@ARGV != 2) {
    die "Usage: $0 input_file output_file\n";
}

my ($input_file, $output_file) = @ARGV;

my $print_lines = 0;

open(my $input_fh, '<', $input_file) or die "Cannot open input file: $!";
open(my $output_fh, '>', $output_file) or die "Cannot open output file: $!";

while (my $line = <$input_fh>) {

    # PCSX2 uses ANSI escape codes, remove them.
    $line =~ s/\e\[[\d;]*[mK]//g;

    # Remove the timestamp from the log
    # Older PCSX2 versions (the one used by alpine) don't have timestamps on IOP logging
    if ($line =~ /]/) {
        $line =~ s/^.*?\] //;
    }

    if ($line =~ /^\s*===!END/) {
        $print_lines = 0;
    }

    print $output_fh $line if $print_lines;

    if ($line =~ /^\s*===!BEGIN/) {
        $print_lines = 1;
    }
}

close($input_fh);
close($output_fh);
