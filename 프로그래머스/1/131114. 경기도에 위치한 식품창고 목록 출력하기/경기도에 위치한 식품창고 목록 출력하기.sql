-- 코드를 입력하세요
SELECT WAREHOUSE_ID, WAREHOUSE_NAME, address, COALESCE(freezer_yn, 'N') FROM FOOD_WAREHOUSE
    WHERE ADDRESS LIKE '%경기도%'