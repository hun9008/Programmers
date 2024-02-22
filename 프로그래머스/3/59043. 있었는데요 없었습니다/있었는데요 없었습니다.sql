-- 코드를 입력하세요
SELECT INS.ANIMAL_ID, INS.NAME FROM ANIMAL_INS AS INS
    JOIN ANIMAL_OUTS AS OUTS ON INS.ANIMAL_ID = OUTS.ANIMAL_ID
    WHERE OUTS.DATETIME < INS.DATETIME
    ORDER BY INS.DATETIME