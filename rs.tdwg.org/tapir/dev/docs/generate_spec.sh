year=`date -d now +%Y`
month=`date -d now +%m`
day=`date -d now +%d`
python t2t.py -t xhtml --no-headers -i TAPIR_specification_body.t2t -o body.htm
python t2t.py -t xhtml -i TAPIR_specification_header.t2t -o tdwg_tapir_specification_$year-$month-$day.htm
rm -f body.htm
