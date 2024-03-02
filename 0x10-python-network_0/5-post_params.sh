#!/bin/bash

# Check if the URL argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

# Get the URL from the command line argument
url="$1"

# Set variables for email and subject
email="test@gmail.com"
subject="I will always be here for PLD"

# Send a POST request to the URL with the specified variables
response=$(mktemp)
curl -s -X POST -d "email=$email&subject=$subject" -o "$response" "$url"

# Check if curl encountered an error
if [ $? -ne 0 ]; then
    echo "Error: Unable to fetch URL $url"
    exit 1
fi

# Display the body of the response
cat "$response"

# Clean up temporary file
rm -f "$response"
