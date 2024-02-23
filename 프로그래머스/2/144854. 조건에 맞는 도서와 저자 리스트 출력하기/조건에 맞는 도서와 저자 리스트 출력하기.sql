-- 코드를 입력하세요
SELECT B.BOOK_ID, A.AUTHOR_NAME, DATE_FORMAT(B.PUBLISHED_DATE, '%Y-%m-%d') AS PUBLISHED_DATE FROM BOOK B
    JOIN AUTHOR A USING (AUTHOR_ID)
    WHERE CATEGORY LIKE '경제'
    ORDER BY PUBLISHED_DATE