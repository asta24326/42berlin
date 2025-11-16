#!/bin/bash

# Папка для карт
mkdir -p maps
cd maps || exit

# Валидные карты
cat > valid_map_1.ber <<EOL
11111
1P0C1
10001
1C0E1
11111
EOL

cat > valid_map_2.ber <<EOL
111111
1P0001
100C01
1000E1
1C0001
111111
EOL

cat > valid_map_3.ber <<EOL
11111111
1P0000C1
10001101
100C00E1
11111111
EOL

cat > valid_map_4.ber <<EOL
111111111
1P00000C1
100111001
1C00000E1
111111111
EOL

cat > valid_map_5.ber <<EOL
1111111111
1P0000C001
1001111001
1C000000E1
1111111111
EOL

# Неверные карты
cat > invalid_map_1.ber <<EOL
11111
1P0C1
10001
1C0E0
11111
EOL

cat > invalid_map_2.ber <<EOL
111111
1P0001
1C00E1
1001C1
EOL

cat > invalid_map_3.ber <<EOL
11111
1PP0C
100E1
1C001
11111
EOL

cat > invalid_map_4.ber <<EOL
11111
1P00C
10001
1C00E
11110
EOL

cat > invalid_map_5.ber <<EOL
11111
1P0C1
1C001
10001
11111
EOL

echo "All maps have been created in the 'maps' folder."
