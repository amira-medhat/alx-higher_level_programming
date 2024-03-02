#!/bin/bash

# Check if the URL argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

# Get the URL from the command line argument
url="$1"

# Send a DELETE request to the URL and store the response body in a temporary file
response=$(mktemp)
curl -s -X DELETE -o "$response" "$url"

# Check if curl encountered an error
if [ $? -ne 0 ]; then
    echo "Error: Unable to fetch URL $url"
    exit 1
fi

# Display the body of the response
cat "$response"

# Clean up temporary file
rm -f "$response"
