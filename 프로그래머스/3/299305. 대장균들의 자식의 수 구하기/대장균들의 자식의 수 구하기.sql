-- 코드를 작성해주세요
# select E1.ID, (select count(*) from ECOLI_DATA as E2 where E1.ID = E2.PARENT_ID) as CHILD_COUNT
# from ECOLI_DATA as E1
# order by E1.ID;


select E1.ID, count(E2.PARENT_ID) as CHILD_COUNT
from ECOLI_DATA as E1
left join ECOLI_DATA as E2 on E1.ID = E2.PARENT_ID
group by E1.ID
order by E1.ID;

