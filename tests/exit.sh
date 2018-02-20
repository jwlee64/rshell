#!/bin/sh
../bin/rshell << 'EOF'
exit
echo hello || exit 
echo work || exit 
echo exit;
#comment
echo again && exit;
echo one || echo two && echo three && exit
EOF
