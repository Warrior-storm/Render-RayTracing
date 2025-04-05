#!/bin/bash

# Input directory containing .ppm files
INPUT_DIR="frames"

# Output GIF file
OUTPUT_GIF="output.gif"

# Convert .ppm files to GIF using ImageMagick
convert -delay 5 -loop 0 "$INPUT_DIR/*.ppm" "$OUTPUT_GIF"

echo "GIF created: $OUTPUT_GIF"
