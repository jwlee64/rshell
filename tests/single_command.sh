#!/bin/sh
../bin/rshell << 'EOF'
echo hey 
ls 
cd 
exit 
EOF
