#!/bin/bash
# Send a request to the URL and display the body of the response
curl -s "$1" | grep -oP '(?<=<title>).*?(?=</title>)'
