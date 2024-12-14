# Start via `make test-debug` or `make test-release`
async def test_basic(service_client):
    response = await service_client.post(
        '/v1/ping',
    )
    assert response.status == 200
    assert response.text == '1'

    response = await service_client.post(
        '/v1/ping',
    )
    assert response.status == 200
    assert response.text == '2'

