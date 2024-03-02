#!/bin/bash

# Check if the URL argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

# Get the URL from the command line argument
url="$1"

# Send an OPTIONS request to the URL and store the response headers in a temporary file
response=$(mktemp)
curl -s -I -X OPTIONS -o "$response" "$url"

# Check if curl encountered an error
if [ $? -ne 0 ]; then
    echo "Error: Unable to fetch URL $url"
    exit 1
fi

# Display the Allow header from the response, which lists the allowed HTTP methods
allow_header=$(grep -i "^allow:" "$response" | tr -d '\r')

# Check if the Allow header exists
if [ -n "$allow_header" ]; then
    echo "HTTP methods allowed by the server:"
    echo "$allow_header" | awk '{$1=""; print $0}'
else
    echo "Error: Allow header not found in the response"
fi

# Clean up temporary file
rm -f "$response"
