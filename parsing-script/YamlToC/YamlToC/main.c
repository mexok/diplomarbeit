//
//  main.c
//  YamlToC
//
//  Created by Konstantin Merker on 03.08.18.
//  Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#include "yaml.h"

int main(int argc, const char * argv[]) {
    FILE *fh = fopen("/Users/konstantin/Desktop/diplomarbeit/parsing-script/testfiles/test2.yaml", "r");
    yaml_parser_t parser;
    yaml_event_t  event;   /* New variable */
    
    /* Initialize parser */
    if(!yaml_parser_initialize(&parser))
    fputs("Failed to initialize parser!\n", stderr);
    if(fh == NULL)
    fputs("Failed to open file!\n", stderr);
    
    
    unsigned char buffer[2048];
    size_t len = fread(buffer, 1, 2048, fh);
    
    /* Set input file */
    yaml_parser_set_input_string(&parser, buffer, len);
    
    /* START new code */
    do {
        if (!yaml_parser_parse(&parser, &event)) {
            printf("Parser error %d\n", parser.error);
            printf("%s ", parser.problem);
            printf("%s\n", parser.context);
            printf("Line: %lu, Column: %lu\n", parser.problem_mark.line, parser.problem_mark.column);
            exit(EXIT_FAILURE);
        }
        
        switch(event.type)
        {
            case YAML_NO_EVENT: puts("No event!"); break;
            /* Stream start/end */
            case YAML_STREAM_START_EVENT: puts("STREAM START"); break;
            case YAML_STREAM_END_EVENT:   puts("STREAM END");   break;
            /* Block delimeters */
            case YAML_DOCUMENT_START_EVENT: puts("<b>Start Document</b>"); break;
            case YAML_DOCUMENT_END_EVENT:   puts("<b>End Document</b>");   break;
            case YAML_SEQUENCE_START_EVENT: puts("<b>Start Sequence</b>"); break;
            case YAML_SEQUENCE_END_EVENT:   puts("<b>End Sequence</b>");   break;
            case YAML_MAPPING_START_EVENT:  puts("<b>Start Mapping</b>");  break;
            case YAML_MAPPING_END_EVENT:    puts("<b>End Mapping</b>");    break;
            /* Data */
            case YAML_ALIAS_EVENT:  printf("Got alias (anchor %s)\n", event.data.alias.anchor); break;
            case YAML_SCALAR_EVENT:
            printf("Got scalar (value %s)\n", event.data.scalar.value);
            break;
        }
        if(event.type != YAML_STREAM_END_EVENT)
        yaml_event_delete(&event);
    } while(event.type != YAML_STREAM_END_EVENT);
    yaml_event_delete(&event);
    /* END new code */
    
    /* Cleanup */
    yaml_parser_delete(&parser);
    fclose(fh);
    printf("Hello, World!\n");
    
    return 0;
}
