
use warnings;
use strict;

use YAML::Tiny;

sub printYaml{
    my $yaml = shift;
    
    if (ref $yaml eq 'HASH'){
        print "Hash Begin:\n";
        foreach my $key (keys %$yaml){
            print "Key: $key\n";
            printYaml($yaml->{$key});
        }
        print "Hash End.\n";
    }elsif (ref $yaml eq 'ARRAY'){
        print "Array Begin:\n";
        foreach my $value (@$yaml){
            printYaml($value);
        }
        print "Array End.\n";
    }elsif ($yaml and not ref $yaml){
        print "Value: $yaml\n";
    }
}

my $yaml = YAML::Tiny->read('test.yaml');

printYaml($yaml->[0]);

