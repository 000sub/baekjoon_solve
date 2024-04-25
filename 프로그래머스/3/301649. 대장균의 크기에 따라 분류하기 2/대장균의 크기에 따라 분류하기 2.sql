-- 코드를 작성해주세요
select ID,
    case
        when PERCENT_RANK() over (order by SIZE_OF_COLONY desc) <= 0.25 then 'CRITICAL'
        when PERCENT_RANK() over (order by SIZE_OF_COLONY desc) <= 0.5 then 'HIGH'
        when PERCENT_RANK() over (order by SIZE_OF_COLONY desc) <= 0.75 then 'MEDIUM'
        else 'LOW'
    end as COLONY_NAME
from ECOLI_DATA
order by ID;