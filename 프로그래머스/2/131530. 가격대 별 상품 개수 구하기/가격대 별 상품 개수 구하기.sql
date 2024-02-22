# -- 코드를 입력하세요
# SELECT FLOOR(price/10000) * 10000 AS PRICE_GROUP, COUNT(*) AS PRODUCTS FROM PRODUCT
#     GROUP BY PRICE_GROUP
#     ORDER BY PRICE_GROUP


SELECT PRICE - (PRICE % 10000) AS PRICE_GROUP, COUNT(PRICE) AS PRODUCTS FROM PRODUCT
    GROUP BY PRICE_GROUP
    ORDER BY PRICE_GROUP