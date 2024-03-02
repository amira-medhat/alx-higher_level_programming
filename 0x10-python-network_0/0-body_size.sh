#!/bin/bash

# Check if the URL argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

# Get the URL from the command line argument
url="$1"

# Send a request to the URL and store the response body in a temporary file
response=$(mktemp)
curl -s -o "$response" -w "%{size_download}" "$url"

# Check if curl encountered an error
if [ $? -ne 0 ]; then
    echo "Error: Unable to fetch URL $url"
    exit 1
fi

# Get the size of the response body
size=$(cat "$response")

# Display the size in bytes
echo "Size of the response body: $size bytes"

# Clean up temporary file
rm -f "$response"
