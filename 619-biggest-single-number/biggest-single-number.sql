select max(val.num) as num from(
    select num, count(num) as f from MyNumbers
    group by num
) as val 
where f=1
