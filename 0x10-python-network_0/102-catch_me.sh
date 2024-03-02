#!/bin/bash

# Send a POST request with custom headers to 0.0.0.0:5000/catch_me
curl -s -X POST -H "Content-Type: text/plain" -d "You got me!" 0.0.0.0:5000/catch_me
