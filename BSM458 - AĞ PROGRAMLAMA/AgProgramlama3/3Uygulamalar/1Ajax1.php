<?php

require_once "Configuration/DatabaseConnection1.php";

$result = pg_query($baglantiNo, "SELECT * FROM \"Ogrenci\"");

pg_close($baglantiNo);

echo "<table id='mytable'>
		<tr>
			<th>Adı</th>
			<th>Soyadı</th>
		</tr>";

while ($row = pg_fetch_array($result)) {
    echo "
		<tr>
			";
    echo "<td>" . $row['adi'] . "</td>";
    echo "<td>" . $row['soyadi'] . "</td>";
    echo "
		</tr>";
}
echo "</table>";

?>
	

