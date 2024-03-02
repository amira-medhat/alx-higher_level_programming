#!/bin/bash

# Check if the URL argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

# Get the URL from the command line argument
url="$1"

# Send a GET request to the URL and store the response body in a temporary file
response=$(mktemp)
curl -s -o "$response" -w "%{http_code}" "$url"

# Check if curl encountered an error
if [ $? -ne 0 ]; then
    echo "Error: Unable to fetch URL $url"
    exit 1
fi

# Get the HTTP status code from the response
http_status=$(tail -n1 "$response")

# Check if the status code is 200
if [ "$http_status" -eq 200 ]; then
    # Display the body of the response
    sed '$d' "$response"
else
    echo "Error: HTTP status code $http_status"
fi

# Clean up temporary file
rm -f "$response"
