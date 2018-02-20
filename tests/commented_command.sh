#!/bin/sh
../bin/rshell/ << 'EOF'
echo words #comment
echo a && echo b #comment
echo a || echo b #comment
echo a; #comment
exit
EOF
