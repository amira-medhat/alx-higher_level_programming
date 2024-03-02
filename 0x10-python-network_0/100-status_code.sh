#!/bin/bash

# Check if the URL argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

# Get the URL from the command line argument
url="$1"

# Send a request to the URL and store the response headers in a temporary file
response=$(mktemp)
curl -s -I -o "$response" "$url"

# Extract the status code from the response headers
status_code=$(awk '/^HTTP/{print $2}' "$response")

# Display the status code
echo "Status code: $status_code"

# Clean up temporary file
rm -f "$response"
