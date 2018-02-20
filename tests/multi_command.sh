#!/bin/sh
../bin/rshell << 'EOF'
echo a && echo b 
echo a || echo b
echo a; echo b
echo a && echo b || echo c 
EOF
