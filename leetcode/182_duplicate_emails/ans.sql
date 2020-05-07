select Email from ( select Email, count(*) as cnt from sandbox182 group by Email ) B where cnt >= 2;
