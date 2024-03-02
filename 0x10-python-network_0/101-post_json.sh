#!/bin/bash

# Check if both URL and file arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <URL> <file>"
    exit 1
fi

# Get the URL and filename from command line arguments
url="$1"
file="$2"

# Check if the file exists
if [ ! -f "$file" ]; then
    echo "Error: File '$file' does not exist"
    exit 1
fi

# Send a POST request with the contents of the file in the body
response=$(mktemp)
curl -s -X POST -d "@$file" -H "Content-Type: application/json" -o "$response" "$url"

# Check if curl encountered an error
if [ $? -ne 0 ]; then
    echo "Error: Unable to fetch URL $url"
    exit 1
fi

# Display the body of the response
cat "$response"

# Clean up temporary file
rm -f "$response"
