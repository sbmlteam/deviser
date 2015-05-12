#!/usr/bin/env python


def hasSIdRef(attributes):
    hasSidRefs = False
    if any(attribute['type'] == 'SIdRef' for attribute in attributes):
        hasSidRefs = True
    return hasSidRefs
